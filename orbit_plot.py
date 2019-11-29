import matplotlib.pyplot as plt
import numpy as np

data = np.loadtxt("Orbit.txt")
sorted_data = np.transpose(data)

x = sorted_data[0]
y = sorted_data[1]

plt.grid()
plt.plot(x[0],y[0],"o",label="Initial position",color="red")
plt.plot(x,y)
plt.show()
