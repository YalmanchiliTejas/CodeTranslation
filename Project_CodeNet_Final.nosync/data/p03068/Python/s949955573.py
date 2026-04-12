n = input()
s = input()
k = input()

for S in s:
    print(S if S == s[int(k)-1] else "*",end="")