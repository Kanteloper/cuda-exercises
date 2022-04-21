/**
 * Sample Project for studying CUDA - VectorAdd
 */

#include "kernel.cuh"
#include <iostream>

constexpr unsigned int MAX_NUM = 1 << 15;

int main()
{
	size_t maxSize = MAX_NUM * sizeof(float);

	// allocate the host vectors
	float* host_a = (float*)malloc(maxSize);
	float* host_b = (float*)malloc(maxSize);
	float* host_c = (float*)malloc(maxSize);

	if (host_a == nullptr || host_b == nullptr || host_c == nullptr)
	{
		std::cerr << "Failed to allocate host vectors" << std::endl;
		return 0;
	}

	// prepare host data
	for (int i = 0; i < MAX_NUM; ++i)
	{
		host_a[i] = rand() / (float)RAND_MAX;
		host_b[i] = rand() / (float)RAND_MAX;
		host_c[i] = rand() / (float)RAND_MAX;
	}

	// CUDA 11.6에서 cudaMallocManaged, cudaMalloc 시간 비교

	// allocate the device vectors
	cudaError_t err = cudaSuccess;
	float* dev_a, * dev_b, * dev_c;
	err = cudaMalloc((void**)&dev_a, maxSize);
	if (err != cudaSuccess)
	{
		std::cerr << "Failed to allocate device vector A" << std::endl;
		std::cerr << "error: " << cudaGetErrorString(err) << std::endl;
		return 0;
	}

	err = cudaMalloc((void**)&dev_b, maxSize);
	if (err != cudaSuccess)
	{
		std::cerr << "Failed to allocate device vector B" << std::endl;
		std::cerr << "error: " << cudaGetErrorString(err) << std::endl;
		return 0;
	}

	err = cudaMalloc((void**)&dev_c, maxSize);
	if (err != cudaSuccess)
	{
		std::cerr << "Failed to allocate device vector C" << std::endl;
		std::cerr << "error: " << cudaGetErrorString(err) << std::endl;
		return 0;
	}

	// copy array a, b from host to device
	/*HANDLE_ERROR(cudaMemcpy(dev_a, a, MAX_NUM * sizeof(int), cudaMemcpyHostToDevice));
	HANDLE_ERROR(cudaMemcpy(dev_b, b, MAX_NUM * sizeof(int), cudaMemcpyHostToDevice));*/

	// process adding vectors in gpu
	int blocksPerGrid = MAX_NUM;
	int threadsPerBlock = 1;
	//add << < blocksPerGrid, threadsPerBlock >> > (dev_a, dev_b, dev_c);

	// copy array c from device to host
	//HANDLE_ERROR(cudaMemcpy(c, dev_c, MAX_NUM * sizeof(int), cudaMemcpyDeviceToHost));

	// print the result
	/*for (int i = 0; i < MAX_NUM; ++i)
	{
		cout << "\n" << a[i] << " + " << b[i] << " = " << c[i] << endl;
	}*/

	// deallocate gpu memory
	/*cudaFree(dev_a);
	cudaFree(dev_b);
	cudaFree(dev_c);*/

	return 0;
}

