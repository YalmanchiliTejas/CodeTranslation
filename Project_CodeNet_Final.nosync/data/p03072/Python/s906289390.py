N = int(input())
H=list(map(int,input().split()))
list_H =[]
count=0
for i in range(N):
    list_H.append(H[i])
    m_H=max(list_H)
    if H[i]>=m_H:
        count=count+1

print(count)
