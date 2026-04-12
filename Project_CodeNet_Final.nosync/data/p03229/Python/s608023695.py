n = int(input())
listA=[]
index=0
while index < n:
    listA.append(int(input()))
    index+=1
listA.sort()


if len(listA)%2==0:
    sum = listA[len(listA)//2]-listA[len(listA)//2-1]
    index=0
    while index < len(listA):
        if index == len(listA)//2-1 or index == len(listA)//2:
            pass
        else:
            if index < len(listA)//2:
                sum-=2*listA[index]
            else:
                sum+=2*listA[index]
        index+=1
    print(sum)
else:
    sum=-1*(listA[len(listA)//2]+listA[len(listA)//2-1])
    index = 0
    while index < len(listA):
        if index == len(listA)//2-1 or index == len(listA)//2:
            pass
        else:
            if index < len(listA)//2:
                sum -= 2*listA[index]
            else:
                sum += 2*listA[index]
        index += 1
    sumB = listA[len(listA)//2]+listA[len(listA)//2+1]
    index2 = 0
    while index2 < len(listA):
        if index2 == len(listA)//2 or index2 == len(listA)//2+1:
            pass
        else:
            if index2 < len(listA)//2:
                sumB -= 2*listA[index2]
            else:
                sumB += 2*listA[index2]
        index2 += 1

    print(max(sum, sumB))