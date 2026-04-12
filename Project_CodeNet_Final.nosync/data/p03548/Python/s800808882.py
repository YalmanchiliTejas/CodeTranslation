import math
X,Y,Z=map(int,raw_input().split(' '))

#nY+(n+1)Z=X
#n(Y+Z)=X-Z
#n=X-Z/Y+Z

print int(math.floor((X-Z)*1.0/(Y+Z)))
