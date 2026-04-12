a,b,c,x,y = map(int, input().split())

plan_a = c * (2*x) + max(0, y-x) * b
plan_b = c * (2*y) + max(0, x-y) * a
plan_c = a * x + b * y

print(min(plan_a, plan_b, plan_c))