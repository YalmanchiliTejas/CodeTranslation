N=int(input())
H=list(map(int,input().split()))
takasa=0
count=0
for i in range(N):
    if H[i]>=takasa:
        count+=1
    takasa=max(H[i],takasa)
print(count)