//
//  main.cpp
//  9_Counting_Sort
//
//  Created by 세광 on 2021/08/07.
//

#include <iostream>
#include <cmath>

using namespace std;

class CountingSort {
public:
    CountingSort();
    ~CountingSort();
    void Count();
    void Print(int);
    const int GetMax() const;
    
private:
    int max, n;
    int *count, *arr;
};

int main() {
    CountingSort *sort = new CountingSort;
    sort->Count();
    sort->Print(0);
    sort->Print(sort->GetMax() + 1);
    delete sort;
}

CountingSort::CountingSort() {
    cin >> max >> n;
    count = new int[max + 1];
    arr = new int[n];
    memset(count, 0, max * sizeof(count));
    for (int i = 0; i < n; i++) cin >> arr[i];
}


CountingSort::~CountingSort() {
    delete [] count;
    delete [] arr;
    count = NULL;
    arr = NULL;
}

void CountingSort::Count() {
    for (int i = 0; i < n; i++) count[arr[i]]++;
}

void CountingSort::Print(int rhs) {
    for (int i = 1; i <= max; i++) {
        if (count[i] != 0) {
            if (rhs == 0) {
                for (int j = 0; j < count[i]; j++) {
                    cout << i << ' ';
                }
            } else {
                for (int j = 0; j < count[rhs - i]; j++) {
                    cout << rhs - i << ' ';
                }
            }
        }
    }
    cout << endl;
}

const int CountingSort::GetMax() const { return max; }
