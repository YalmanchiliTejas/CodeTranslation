n, x, m = map(int, input().split())
nn = n

slow = x
fast = x
out = 0

while n:
    if n != nn and slow == fast:
        break
    out += slow
    n -= 1

    slow = (slow * slow) % m
    fast = (fast * fast) % m
    fast = (fast * fast) % m

head = slow
curr_sum = slow
curr_count = 1
slow = (slow * slow) % m
while slow != head:
    curr_count += 1
    curr_sum += slow
    slow = (slow * slow) % m

while n % curr_count:
    out += slow
    n -= 1
    slow = (slow * slow) % m

out += (n // curr_count) * curr_sum
print(out)
