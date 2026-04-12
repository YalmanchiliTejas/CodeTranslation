n = int(input())
s = [0 for _ in range(26)]
t = [0 for _ in range(26)]
   
ans = ""

for i in range(n):
    s1 = input()
    if i == 0:
        for j in range(len(s1)):
            s[ord(s1[j]) - ord("a")] += 1
    else:
        for j in range(len(s1)):
            t[ord(s1[j]) - ord("a")] += 1
        for j in range(26):
            s[j] = min(s[j], t[j])
            t[j] = 0
        
for i in range(26):
    ans += chr(ord("a") + i) * s[i]
    
print(ans)