N = int(input())
s = input()
K = int(input())

tmp = s[K-1]

res = ""
for i in range(N):
    if s[i] != tmp:
        res += '*'
    else:
        res += s[i]
        
print(res)