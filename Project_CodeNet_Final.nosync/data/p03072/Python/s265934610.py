N=int(input())
H=list(map(int,input().split()))
i=0
counter=0
saidai=0
while i<N:
    if saidai<=H[i]:
        saidai=H[i]
        counter=counter+1
    i=i+1
print(counter)
