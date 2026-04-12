
import collections


class Solution:
    def solve(self, string):
        counts = collections.Counter(string)

        return counts["A"] and counts["B"]


sol = Solution()

string = input().strip()

print("Yes" if sol.solve(string) else "No")
