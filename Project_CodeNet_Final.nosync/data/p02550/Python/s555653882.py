import sys
n, x, m = map(int, input().split())
A = [0] * (10**5 + 1)
val = x
val_visited = set()
val_record = []
for i in range(n):
    if val in val_visited:
        break
    val_visited.add(val)
    val_record.append(val)
    val = val**2 % m
else:
    print(sum(val_record))
    sys.exit()

entry_idx = val_record.index(val)
loop_len = len(val_record) - entry_idx
loop_total_val = sum(val_record[entry_idx:])
head_len = len(val_record)

n -= head_len
loop_num = n // loop_len
tail_len = n % loop_len

ans = 0
#head
ans += (sum(val_record))
#loop
ans += loop_total_val * loop_num
#tail
for i in range(tail_len):
    ans += val_record[entry_idx + i]
print(ans)