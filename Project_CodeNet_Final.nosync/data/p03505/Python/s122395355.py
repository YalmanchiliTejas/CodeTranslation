K, A, B = map(int, raw_input().split())
if K <= A:
    print 1
elif A <= B:
    print -1
else:
    print (K-B-1)/(A-B)*2+1