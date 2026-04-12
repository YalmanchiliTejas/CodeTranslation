a,b,c,x,y=map(int,input().split())
a_b_all=a*x+b*y
ab_all=(c*2)*max(x,y)
mix_a_all=(c*2)*x+b*(y-x)
mix_b_all=(c*2)*y+a*(x-y)
mix_all=max(mix_a_all,mix_b_all)
print(min(a_b_all,ab_all,mix_all))