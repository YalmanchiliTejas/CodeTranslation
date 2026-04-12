N=int(input())
while N!=0:
    data=[]
    for i in range(N):
        data.append(int(input()))
    data.sort()
    Sum=0
    Count=0
    for i in range(N-2):
        Sum+=data[i+1]
        Count+=1
    print(Sum//Count)
    N=int(input())

