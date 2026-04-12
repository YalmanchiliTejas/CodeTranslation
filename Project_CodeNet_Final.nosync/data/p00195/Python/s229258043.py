D = "ABCDE"
while True:
    try:
        A = [(D[i],sum(map(int,raw_input().split()))) for i in xrange(5)]
    except:
        break
    print "{} {}".format(*max(A,key=lambda (i,a):a))