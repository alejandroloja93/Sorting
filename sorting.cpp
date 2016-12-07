#include <iostream>
#include<algorithm>
#include<array>


template<size_t size>
void bubble_sort(std::array<int,size>& arr)  
{

	for(int i=0; i< arr.size(); ++i)
		for(int j=0; j<arr.size() - 1 -i; ++j)
			if(arr[j]>arr[j+1])
				std::swap(arr[j],arr[j+1]);
}

template<size_t size>
void insertion_sort(std::array<int , size>& arr)
{

	for(int i = 1; i < arr.size(); ++i)
		for(int j=i; j>0; --j)
			if(arr[j] < arr[j-1])
				std::swap(arr[j],arr[j-1]);
				
}

template<size_t size>
void quick_sort(std::array<int, size>& arr, int left, int right)
{
	int i = left, j = right;
	int pivot = arr[(i+j)/2];
	while(i < j){
		while(arr[i] < pivot) ++i;
		while(arr[j] > pivot ) --j;
		
	if(i <= j){
		std::swap(arr[i], arr[j]);
		++i;
		--j;
		}
	
	}
	if(left < j) quick_sort(arr, left, j);
	if(i < right) quick_sort(arr, i, right);


}

int main()
{
	std::array<int,9> a{12,45,1,34,56,23,3,8,4};
	
	int left = 0;
	int right = a.size()-1;
	
	
	//insertion_sort(a);
	//bubble_sort(a);
	quick_sort(a, left, right);
	
	for(auto i:a)
		std::cout<<i<<" ";
		
	std::cout << std::endl;
		
		
		
		


}
