
n  = int( input() )
s = input()
k = int(input())

ans = ''

for c in s:
    ans += c if c == s[k-1] else '*'

print(ans)