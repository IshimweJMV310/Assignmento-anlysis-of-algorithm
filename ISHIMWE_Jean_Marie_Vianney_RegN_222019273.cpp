#include<iostream>
#include<vector>
#include<random>

/** Implement the sorting algorithms below.
 Don't change the main function. You can define helper functions
 if you need to. 
 If you run the program now, it shoulprint : sorted:0
 As you implement the sorting algorithms,
  the sorted value increment by 1 for each sorting algorithm
  successfully implemented. 
  When all functions are correctly defined,
  your program should display: sorted:5
**/

template <typename T>
void swap (T& a, T& b) {
    int temp = a;
    a = b;
    b = temp;
}

template <typename T>
void check (const std::vector<T> v){
    for (T el : v)
    std::cout<<el<<"\n";
}

template <typename T>
void bubbleSort(std::vector<T>& v)
{
    bool swapped = true;
    while (swapped)
    {
        swapped = false;
        for (int i=0; i < v.size()-1; i++){
            if (v.at(i) > v.at(i+1))
            {
                swap (v[i],v[i+1]);      
                swapped = true;   
            }
        }
    } 
}

template <typename T>
void insertionSort(std::vector<T>& v)
{
    for (size_t i = 1; i < v.size(); i++)
    {
        int rightpo = i;
        int prevpo = rightpo -1;

        while (prevpo >= 0 ) {

            if(v.at(rightpo) < v.at(prevpo)) {
                swap (v[rightpo],v[prevpo]);
                rightpo = prevpo;
            }

            --prevpo;
        }
    }
}


template <typename T>
void selectionSort (std::vector<T>& v)
{
    for (size_t i = 0; i < v.size()-1; i++)
    {
        int  smallest = i;
        for (size_t j = i+1; j < v.size() ; j++)
        {

            
            if (v.at(smallest) > v.at(j) ){
                smallest = j;
            }
        }
        
        if (smallest != i)
            swap(v[smallest],v[i]);
    }
    
}

template <typename T>
int partition(std::vector<T>& v, int lower, int higher) {
    int pivot = higher; 
    int left = lower;  

    for (int right = lower; right < higher; right++) {
        if (v[right] < v[pivot]) {
            swap(v[left], v[right]); 
            left++;                  
        }
    }

    swap(v[left], v[pivot]); 
    return left;             
}

template <typename T>
void quickSort(std::vector<T>& v, int lower, int higher) {
    if (lower < higher) {
        int pivot = partition(v, lower, higher); 

        quickSort(v, lower, pivot - 1); 
        quickSort(v, pivot + 1, higher); 
    }
}

template <typename T>
void quickSort(std::vector<T>& v) {
    quickSort(v, 0, v.size() - 1); 
}

template <typename T>
void merge(std::vector<T>& v, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    std::vector<T> L(n1);
    std::vector<T> R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = v[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = v[mid + 1 + j];
    int i = 0; 
    int j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }
    while (i < n1) {
        v[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2) {
        v[k] = R[j];
        ++j;
        ++k;
    }
}

template <typename T>
void mergeSort(std::vector<T>& v, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2; 
        mergeSort(v, left, mid);
        mergeSort(v, mid + 1, right);
        merge(v, left, mid, right);
    }
}

template <typename T>
void mergeSort(std::vector<T>& v) {
    mergeSort(v, 0, v.size() - 1);
}
template<typename T>
bool isSorted(const std::vector<T>& v )
{
    for(size_t i=0; i<v.size()-1;++i)
      if(v.at(i)>v.at(i+1)) return false;
    return true;
}


int main()
{
 std::vector<int> v1{23,45,12,7,6,9,3};
 std::vector<int> v3{4,3,2,1,7,8,9,6};
 std::vector<int> v4{3,6,1,7,9,8,2,4,5};
 std::vector<int> v5{22,44,33,11,66,55,88,77};
 std::vector<int> v2{9,2,3,1,7,8,6,4,5};
 bubbleSort(v1);
 insertionSort(v2);
 selectionSort(v3);
 quickSort(v4);
 mergeSort(v5);
 std::vector<std::vector<int>> vectors;
 vectors.push_back(v1);
 vectors.push_back(v2);
 vectors.push_back(v3);
 vectors.push_back(v4);
 vectors.push_back(v5);
 int sorted=0;
 for (auto v: vectors)
     if( isSorted(v)) ++sorted;
 std::cout<<"sorted :"<<sorted<<"\n";
//  check (v2);
}
