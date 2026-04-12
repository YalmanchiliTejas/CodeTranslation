n = int(input())
s = input()
l = s[int(input())-1]

ans = ""
for i in range(n):
    if s[i] != l:
        ans +="*"
    else:
        ans +=l
print(ans)
