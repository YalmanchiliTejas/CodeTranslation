n=int(input())
al={keys:[0 for i in range(n)] for keys in [chr(ord('a') + j) for j in range(26)]}
for i in range(n):
    s=input()
    for j in s:
        al[j][i]+=1
x=""
for i in [chr(ord('a') + j) for j in range(26)]:
    x+=i*min(al[i])
print(x)