n = int(input())
s_ = input()
k = int(input()) - 1

ans = ''
for i, s in enumerate(s_):
    if s != s_[k]:
        ans += '*'
    else:
        ans += s
print(ans)