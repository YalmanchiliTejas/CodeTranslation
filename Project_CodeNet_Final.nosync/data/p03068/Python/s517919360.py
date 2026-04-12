def solve(n, s, k):
    return "".join([("*" if s[i] != s[k-1] else s[i]) for i in range(n)])

n = int(input())
s = input()
k = int(input())
print(solve(n, s, k))