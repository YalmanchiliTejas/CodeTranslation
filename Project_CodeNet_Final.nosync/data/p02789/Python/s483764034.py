
class Solution:
    def solve(self, n, m):
        return n == m


sol = Solution()

[n, m] = list(map(int, input().strip().split(" ")))

print("Yes" if sol.solve(n, m) else "No")
