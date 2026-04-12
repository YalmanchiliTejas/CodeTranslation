def numOfPutty(l,k):
    if l == 0:
        return 1
    elif k == 1 :
        return 0
    elif k == pow(2,l+2) - 3:
        return pow(2,l+1) - 1
    elif k < pow(2,l+1) -1:
        return numOfPutty(l-1,k-1)
    elif k == pow(2,l+1) - 1 :
        return pow(2,l)
    elif k > pow(2,l+1) - 1:
        return numOfPutty(l-1,k-pow(2,l+1)+1) + pow(2, l )

L , X = map(int, input().split())
print(numOfPutty(L,X))