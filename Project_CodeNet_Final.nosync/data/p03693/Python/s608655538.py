r,g,b=map(int,raw_input().split())
print "YES" if (r*100+g*10+b)%4==0 else "NO"