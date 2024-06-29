#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vb = vector<bool>;

constexpr auto kMax = 4 * 1000000000LL;
const auto kSqrt = static_cast<ll>(sqrt(kMax + 1)) + 1;

ll t, n;
vb sieve{};
vl primes{};

void Ready() {
  sieve = vb(kSqrt + 1, true);
  sieve[0] = false;
  sieve[1] = false;
  for (auto i = 2LL; i <= kSqrt; ++i) {
    if (!sieve[i]) continue;
    primes.push_back(i);

    for (auto j = i + i; j <= kSqrt; j += i) {
      sieve[j] = false;
    }
  }
}

bool IsPrime(ll x) {
  if (x <= 1) return false;

  for (const auto& d : primes) {
    if (x <= d) break;

    if (0 == x % d) {
      return false;
    }
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Ready();

  cin >> t;
  while (0 < (t--)) {
    cin >> n;
    while (true) {
      if (IsPrime(n)) {
        cout << n << '\n';
        break;
      }

      ++n;
    }
  }

  return 0;
}