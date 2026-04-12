def M(i,j):
    return "F" if i=="T" and j=="F" else "T"

n = int(input())
p = input().split()

ret = p[0]
for i in range(1,n):
    ret = M(ret,p[i])
print(ret)

