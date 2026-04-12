a,b,c,x,y=map(int,input().split())

#a,bピザをx,y用意する
#シンプルに用意する場合a*x+b*y
#abピザがa+bより安い場合代替する

ans1 = c*2*(max(x,y))
ans2 = a*x+b*y
ans3 = c*2*y+max((x-y),0)*a
ans4 = c*2*x+max((y-x),0)*b

print(min(ans1,ans2,ans3,ans4))