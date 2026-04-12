NUM = int(input())

#print(NUM)


A = list(map(int,input().split()))
#print(A)


COUNT = 0
for i in range(NUM):
    PRECOUNT = 0
    
    for j in range(NUM-i):
        if A[NUM - i - 1] >= A[j]:
            PRECOUNT += 1
   
    if PRECOUNT == NUM-i:
        COUNT += 1
print(COUNT)