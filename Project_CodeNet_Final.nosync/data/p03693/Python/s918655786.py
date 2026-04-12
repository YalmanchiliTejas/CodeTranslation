A,B,C =[int(x) for x in input().split()]
print("YES" if(A*100+B*10+C)%4==0 else "NO")