class Solution:
    def solve(self, S: str) -> str:

        if S == 'AAA' or S == 'BBB':
            return 'No'
        else:
            return 'Yes'


if __name__ == '__main__':

    # standard input
    S = input()

    # solve
    solution = Solution()
    print(solution.solve(S))
