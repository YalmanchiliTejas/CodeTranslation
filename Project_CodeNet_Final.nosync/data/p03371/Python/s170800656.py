A, B, C, X, Y = map(int, raw_input().split())

#print A, B, C, X, Y

currentX = X
currentY = Y
currentH = 0

#print cost_A, cost_B
while (currentX>0)or(currentY>0):
    if currentX > 0:
        tmpX = currentX - 1
    if currentY > 0:
        tmpY = currentY - 1
    if ((tmpX * A) +(tmpY * B) +((currentH + 2) * C)) < ((currentX * A) +(currentY * B) +((currentH) * C)):
        if currentX > 0:
            currentX -= 1
        if currentY > 0:
            currentY -= 1
        currentH += 2
    else:
        break

#print ((currentX * A) +(currentY * B) +((currentH) * C)),currentX, currentY, currentH
print ((currentX * A) +(currentY * B) +((currentH) * C))
