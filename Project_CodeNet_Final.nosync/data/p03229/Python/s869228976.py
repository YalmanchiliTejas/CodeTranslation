N = int(input())
A = []
for i in range(N):
    A.append(int(input()) )

B=sorted(A)
#print(B[N-1]-B[0] + B[N-1]-B[0])
hN=int(N/2)
cnt=0
C=[]
if N ==2:
    print(B[1]-B[0])
    exit()

if N %2 == 0:
    C.append(B[hN])
    for i in range(hN-1):
        C.append(B[N-1-i])
        C.append(B[i])
    C.append(B[hN-1])
else:
    C.append(B[hN])
    for i in range(hN):
        C.append(B[N-1-i])
        C.append(B[i])

#print(C)

for i in range(1,N):
    cnt+=abs(C[i]-C[i-1])

C=[]
cnt2=0
if N %2 == 0:
    C.append(B[hN])
    for i in range(hN-1):
        C.append(B[i])
        C.append(B[N-1-i])
    C.append(B[hN-1])
else:
    C.append(B[hN])
    for i in range(hN):
        C.append(B[i])
        C.append(B[N-1-i])

#print(C)
for i in range(1,N):
    cnt2+=abs(C[i]-C[i-1])

print(max(cnt,cnt2))