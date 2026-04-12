import sys
N, X, M = map(int, input().split())

now = X
temp_answer = now
exists = set([now])
order = [now]
rewards = [now]

for i in range(N-1):
    now = now**2 % M
    #print(now, exists)
    if now in exists:
        pre = order.index(now)
        circle = i+1 - pre
        circle_reward = rewards[-1] + now - rewards[pre]
        stopped = i + 1
        temp_answer += now
        break
    exists.add(now)
    order.append(now)
    rewards.append(rewards[-1] + now)
    temp_answer += now
else:
    print(temp_answer)
    sys.exit()

N = N - (stopped)
answer = temp_answer

answer += circle_reward * ((N-1)//circle)
rest = (N-1) % circle

for i in range(rest):
    now = now**2 % M
    answer += now

print(answer)