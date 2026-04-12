
def resolve():
  N, X, M = map(int, input().split(" "))
  checked = [False] * M
  val = X
  ans = 0
  val_list = []

  base = M
  for i in range(N):
    if checked[val] != False:
      loop_start_index = checked[val]
      loop_vals = val_list[loop_start_index:]
      loop_val = sum(loop_vals)
      loop_length = len(val_list[loop_start_index:])
      
      if loop_length != 0:
        ans += ((N - i) // loop_length) * loop_val

        for i in range(((N - i) % loop_length)):
          ans += loop_vals[i]
      break
    ans += val
    checked[val] = i
    val_list.append(val)

    val*=val
    if val >= base:
      val %= base


  print(ans)

if __name__ == "__main__":
  resolve()