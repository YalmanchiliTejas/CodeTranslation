
class Solution:
    def solve(self, N: int, M: int) -> str:
        if N == M:
            return 'Yes'
        else:
            return 'No'


if __name__ == '__main__':

    # standard input
    N, M = map(int, input().split())

    # solve
    solution = Solution()
    print(solution.solve(N, M))
