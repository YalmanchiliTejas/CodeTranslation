N = int(input())
S = input()
K = int(input())

a = S[K-1]

ans = ''.join(['*' if x != a else x for x in S])

print(ans)