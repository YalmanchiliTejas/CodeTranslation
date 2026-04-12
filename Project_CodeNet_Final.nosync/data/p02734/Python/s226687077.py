n, s = map(int, input().split())
a = list(map(int, input().split()))
modval = 998244353

def update(newval, length_elems):
  # sequences made up of only the new value
  if newval<= s:
    new_state[newval][0] = length_elems
    new_state[newval][1] = length_elems
  # appending to existing sequences
  for j in range(1, s+1):
    new_state[j][0] = (new_state[j][0] + old_state[j][0])%modval
    new_state[j][1] = (new_state[j][1] + old_state[j][0] + old_state[j][1])%modval
    if newval+j <= s:
      new_state[newval+j][0] = (new_state[newval+j][0] + old_state[j][0])%modval
      new_state[newval+j][1] = (new_state[newval+j][1] + old_state[j][0])%modval

# [[combos without R, combos with R] that add to a given target]
old_state = [[0, 0] for _ in range(s+1)]
for i, newval in enumerate(a, 1):
  # reset the new state to zeros
  new_state = [[0, 0] for _ in range(s+1)]
  # create new state from old state
  update(newval, i)
  # old state now point to new state
  old_state = new_state
print(new_state[s][1]%modval)