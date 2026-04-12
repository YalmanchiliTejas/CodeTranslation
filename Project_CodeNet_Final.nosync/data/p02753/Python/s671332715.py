import sys
input = lambda: sys.stdin.readline().rstrip()
input_nums = lambda: list(map(int, input().split()))

s = input()
if s[0] == s[1] and s[1] == s[2]:
    print('No')
else:
    print('Yes')