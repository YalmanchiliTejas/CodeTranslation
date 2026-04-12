n = int(input())

ans = [50]*26

al = list("abcdefghijklmnopqrstuvwxyz")

for i in range(n):
    t = input()
    for s in range(26):
        ans[s] = min(ans[s],t.count(al[s]))
        
for i in range(26):
    for t in range(ans[i]):
        print(al[i],end = "")