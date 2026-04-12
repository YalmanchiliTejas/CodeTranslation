n=int(input())

gohan=800*n
if n>=15:
    cnt=n//15
    total=gohan-200*cnt
    print(total)
else:
    print(gohan)