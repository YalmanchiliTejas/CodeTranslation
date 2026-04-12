N=int(raw_input())
P=raw_input().split()
b=P[-1::-2]+P[N%2::2]
print " ".join(b)