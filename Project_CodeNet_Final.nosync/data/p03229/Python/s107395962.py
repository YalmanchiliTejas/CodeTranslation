from collections import deque

n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))

stack = deque(sorted(a))
one = 0
right = stack.pop()
left = right
count = 0
while stack:
    if count % 2 == 0:
        if len(stack) >= 2:
            stack_right = stack.popleft()
            stack_left = stack.popleft()
            one += abs(stack_right - right) + abs(stack_left - left)
            right = stack_right
            left = stack_left
        else:
            stack_one = stack.pop()
            one += max(abs(stack_one - right), abs(stack_one - left))
    else:
        if len(stack) >= 2:
            stack_right = stack.pop()
            stack_left = stack.pop()
            one += abs(stack_right - right) + abs(stack_left - left)
            right = stack_right
            left = stack_left
        else:
            stack_one = stack.pop()
            one += max(abs(stack_one - right), abs(stack_one - left))
    count += 1
stack = deque(sorted(a))
two = 0
right = stack.popleft()
left = right
count = 0
while stack:
    if count % 2 == 1:
        if len(stack) >= 2:
            stack_right = stack.popleft()
            stack_left = stack.popleft()
            two += abs(stack_right - right) + abs(stack_left - left)
            right = stack_right
            left = stack_left
        else:
            stack_one = stack.pop()
            two += max(abs(stack_one - right), abs(stack_one - left))
    else:
        if len(stack) >= 2:
            stack_right = stack.pop()
            stack_left = stack.pop()
            two += abs(stack_right - right) + abs(stack_left - left)
            right = stack_right
            left = stack_left
        else:
            stack_one = stack.pop()
            two += max(abs(stack_one - right), abs(stack_one - left))
    count += 1
print(max(one, two))