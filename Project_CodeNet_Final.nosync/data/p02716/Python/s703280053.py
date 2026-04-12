n = int(input())
a = list(map(int, input().split()))
# at any partial solution, it is only possible to
# have either ceil(k/2) or ceil(k/2)-1 included values
# also, for the next solution, it matters if the current value was used or not.
# therefore, keep a partial 'max solution' for all 4 possibilities:
# ceil(k/2)-1, not included
# ceil(k/2)-1, included
# ceil(k/2), not included
# ceil(k/2), included
def solve(start_point):
  for idx, value in enumerate(a[start_point:]):
    idx = idx+start_point
    if idx%2!=0:
      partial_solution[idx][0] = max(partial_solution[idx-1][0], partial_solution[idx-1][1])
      partial_solution[idx][1] = a[idx] + max(partial_solution[idx-2][0], partial_solution[idx-2][1])
      partial_solution[idx][2] = max(partial_solution[idx-1][2], partial_solution[idx-1][3])
      partial_solution[idx][3] = a[idx] + partial_solution[idx-1][0]
    else:
      partial_solution[idx][0] = max(partial_solution[idx-1][2], partial_solution[idx-1][3])
      partial_solution[idx][1] = a[idx] + partial_solution[idx-1][0]
      partial_solution[idx][2] = float('-inf')
      partial_solution[idx][3] = a[idx] + partial_solution[idx-1][2]
  if n%2==0:
    return(max(partial_solution[n-1][2], partial_solution[n-1][3]))
  return(max(partial_solution[n-1][0], partial_solution[n-1][1]))
partial_solution = [[float('-inf') for _ in range(4)] for _ in range(len(a))]
partial_solution[0] = [0, float('-inf'), float('-inf'), a[0]]
# partial_solution[1] = [0, float('-inf'), a[0], a[1]]
# partial_solution[2] = [max(a[:2]), a[2], float('-inf'), a[0]+a[2]]
# partial_solution[3] = [max(a[:3]), a[3], a[0]+a[2], max(a[0]+a[3], a[1]+a[3])]
print(solve(start_point=1))