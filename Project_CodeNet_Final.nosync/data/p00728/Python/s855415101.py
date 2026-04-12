person = int(input())
while person != 0:
    scores = []
    for i in range(person):
        scores.append(int(input()))     
    scores.sort()
    del scores[0]
    del scores[-1]
    print(int(sum(scores)/len(scores)))
    person = int(input())
