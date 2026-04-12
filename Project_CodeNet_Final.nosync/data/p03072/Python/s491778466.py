N = input()
H = map(int, raw_input().split())
print 1+sum(max(H[:i])<=H[i] for i in range(1,N))
