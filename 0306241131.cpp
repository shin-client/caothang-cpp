#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;
#define faster() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef long long ll;

int linearSearch(const vector<int>& a, int n, int k) {
  for (int i = 0; i < n; ++i)
    if (a[i] == k) return i;
  return -1;
}

int binSearch(const vector<int>& a, int l, int r, int k) {
  int res = -1;
  while (l <= r) {
    int m = l + (r - l) / 2;
    if (a[m] == k) {
      res = m;
      r = m - 1;
    }
    else if (a[m] < k) l = m + 1;
    else r = m - 1;
  }
  return res;
}

int binSearch_recursive(const vector<int>& a, int l, int r, int k) {
  if (l >= r) {
    int m = l + (r - l) / 2;
    if (a[m] == k) return m;
    if (a[m] > k) return binSearch_recursive(a, l, m - 1, k);
    return binSearch_recursive(a, m + 1, r, k);
  }
  return -1;
}

void interchangeSort(vector<int>& a, int n) {
  for (int i = 0; i < n - 1; ++i)
    for (int j = i + 1; j < n; ++j)
      if (a[i] > a[j]) swap(a[i], a[j]);
}

int main() {
  faster();
  freopen("test4.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  // Code
  
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;
  
  auto start = high_resolution_clock::now(); // Start

  int res = linearSearch(a, n, k);
  
  auto stop = high_resolution_clock::now(); // Stop
  
  cout << res;

  // End code

  // Measure execution time
  cout << endl;
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: "
       << duration.count() << " microseconds";
  return 0;
}