#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
  // Số lượng phần tử cần tạo (điều chỉnh theo nhu cầu)
  const int numElements = 1000000; 

  // Tạo vector để lưu trữ các phần tử
  vector<int> data(numElements);

  // Tạo generator số ngẫu nhiên
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> distrib(1, 1000); // Giá trị tối đa 1 triệu

  // Tạo các phần tử ngẫu nhiên và lưu vào vector
  for (int i = 0; i < numElements; ++i) {
    data[i] = distrib(gen);
  }

  // Sắp xếp vector theo thứ tự tăng dần
  sort(data.begin(), data.end());

  // Mở file để ghi kết quả
  ofstream outputFile("test2.txt"); // Thay "output.txt" bằng tên file bạn muốn

  outputFile << "1000000 131\n";

  if (outputFile.is_open()) {
    // Ghi các phần tử vào file
    for (int i = 0; i < numElements; ++i) {
      outputFile << data[i] << " ";
    }
    outputFile.close();
    cout << "Đã ghi kết quả vào file test.txt" << endl;
  } else {
    cout << "Không thể mở file để ghi." << endl;
  }

  return 0;
}