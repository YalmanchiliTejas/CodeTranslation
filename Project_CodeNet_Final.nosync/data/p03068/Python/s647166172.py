n = int(input())
s = input()
k = int(input())
ans = ['*' if s[k-1] != s[i] else s[i] for i in range(n)]
print(''.join(ans))