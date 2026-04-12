def f(v,i):s,n=4*2**v-3,2*2**v-1;m=s/2+1;return 0 if i<1 or i>s else[0,f(v-1,i-1),n/2+1,f(v-1,i-m)+n/2+1,n,1][(i>1)+(i>=m)+(i>m)+(i>=s)+(v==0)*3]
print f(*map(int,raw_input().split()))