n = int(input())

alp = [float("inf")]*200

for i in range(n):
    S = input()
    tmp = [0]*200
    for s in S:
        tmp[ord(s)] += 1
    for ind in range(200):
        alp[ind] = min(alp[ind],tmp[ind])

ans = ""
for i in range(200):
    ans += chr(i)*alp[i]
    
print(ans)