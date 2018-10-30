#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& a, vector<int>& temp, int leftPos, int rightPos, int rightEnd){
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;
    
    while(leftPos <= leftEnd && rightPos <= rightEnd)
        if(a[leftPos] <= a[rightPos])
            temp[tmpPos++] = std::move(a[leftPos++]);
        else
            temp[tmpPos++] = std::move(a[rightPos++]);
    
    while(leftPos <= leftEnd)       //Copy remaining first half
        temp[tmpPos++] = std::move(a[leftPos++]);
        
    while(rightPos <= rightEnd)     ////Copy remaining second half
        temp[tmpPos++] = std::move(a[rightPos++]);
        
    //Copy back temp array
    for(int i=0; i<numElements; ++i, --rightEnd)
        a[rightEnd] = std::move(temp[rightEnd]);
}


void mergeSort(vector<int>& a, vector<int>& temp, int left, int right){
    if(left < right){
        int center = (left + right) / 2;
        mergeSort(a, temp, left, center);
        mergeSort(a, temp, center+1, right);
        merge(a, temp, left, center+1, right);
    }
}

void mergeSort(vector<int>& a){
    int size = a.size();
    vector<int> temp(size);
    mergeSort(a, temp, 0, size-1);
}

int main()
{
    vector<int> v1 = {2,4,1,6,7,36,23};
    mergeSort(v1);
    std::cout<<"Sorted array is:\n";
    for(int i=0; i<v1.size(); i++)
        std::cout<<v1[i]<<" ";
    return 0;
}
