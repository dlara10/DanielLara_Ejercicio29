import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data = np.loadtxt("onda.dat")


x = len(data)
y = len(data[0])
xx, yy = np.meshgrid(x, y, sparse=True)
z = np.sin(xx**2 + yy**2) / (xx**2 + yy**2)
fig = plt.figure()
plt.subplot(1,2,1)
Axes3D.plot_surface(x,y,z)
plt.imshow(data)
ax.set_xlabel("Tiempo (segundos)")
ax.set_ylabel("Posicion (metros)")
ax.set_zlabel('z');
plt.colorbar(label="Onda")

plt.subplot(1,2,2)
plt.plot(data[0,:], label="tiempo inicial")
plt.plot(data[-1,:], label="tiempo final")
plt.xlabel("Posicion(metros)")
plt.ylabel("Desplazamiento (metros)")
plt.legend()
plt.savefig("plot.png", bbox_="tight")
