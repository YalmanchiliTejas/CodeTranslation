cost_a,cost_b,cost_ab,num_a,num_b = map(int,input().split())
if num_a > num_b:
  num_ab = num_b * 2
  need_a = num_a - (num_ab // 2)
  cost1 = need_a * cost_a + num_ab * cost_ab
  
  num_ab = num_a * 2
  cost3 = num_ab * cost_ab
  cost1 = min(cost1,cost3)
elif num_a < num_b:
  num_ab = num_a * 2
  need_b = num_b - (num_ab // 2)
  cost1 = need_b * cost_b + num_ab * cost_ab

  num_ab = num_b * 2
  cost3 = num_ab * cost_ab
  cost1 = min(cost1,cost3)
else:
  num_ab = num_b * 2  
  cost1 = num_ab * cost_ab

cost2 = cost_a * num_a + cost_b * num_b
ans = min(cost1,cost2)
print(ans)


