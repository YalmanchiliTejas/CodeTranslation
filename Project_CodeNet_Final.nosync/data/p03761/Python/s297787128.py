n = int(input())
s = [input() for _ in range(n)]
t = ""
for i in set(s[0]):
    #print(i)
    if all(i in s[j] for j in range(n)):
        t += i * min(s[k].count(i) for k in range(len(s)))
    #print(t)
    
print(''.join(sorted(t)))