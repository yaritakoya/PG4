#include <iostream>
#include <map>

enum class WeaponId {
	Handgun = 100,
	SubmachineGun = 300,
	RocketLauncher = 900,
};

int main() {
	std::map<WeaponId, int> weaponBulletCounts;

	// operator[] registers weapons in an empty map.
	weaponBulletCounts[WeaponId::Handgun] = 12;
	std::cout << "Pick up Handgun: "
		<< weaponBulletCounts[WeaponId::Handgun] << " bullets\n";

	weaponBulletCounts[WeaponId::SubmachineGun] = 30;
	std::cout << "Pick up SubmachineGun: "
		<< weaponBulletCounts[WeaponId::SubmachineGun] << " bullets\n";

	// operator[] also updates the value for an existing key.
	weaponBulletCounts[WeaponId::Handgun] += 20;
	std::cout << "Update Handgun: "
		<< weaponBulletCounts[WeaponId::Handgun] << " bullets\n";

	// find checks ownership. The iterator's first is the key and second
	// is the bullet count paired with that key.
	const WeaponId selectedWeapon = WeaponId::Handgun;
	auto itWeapon = weaponBulletCounts.find(selectedWeapon);
	if (itWeapon == weaponBulletCounts.end()) {
		std::cout << "Weapon not owned\n";
	} else {
		std::cout << "Selected weapon has " << itWeapon->second
			<< " bullets\n";
		if (itWeapon->second <= 0) {
			std::cout << "Out of bullets\n";
		} else {
			--itWeapon->second;
			std::cout << "Fire Handgun: " << itWeapon->second
				<< " bullets left\n";
		}
	}

	// erase removes the key and its value from the map.
	weaponBulletCounts.erase(WeaponId::Handgun);
	std::cout << "Drop Handgun\n";

	// Mini exercise: register and fire the RocketLauncher.
	weaponBulletCounts[WeaponId::RocketLauncher] = 5;
	std::cout << "Pick up RocketLauncher: "
		<< weaponBulletCounts[WeaponId::RocketLauncher] << " bullets\n";

	itWeapon = weaponBulletCounts.find(WeaponId::RocketLauncher);
	if (itWeapon != weaponBulletCounts.end() && itWeapon->second > 0) {
		--itWeapon->second;
		std::cout << "Fire RocketLauncher: " << itWeapon->second
			<< " bullets left\n";
	}

	// A range-based for loop lists owned weapons and their bullet counts.
	for (const auto& entry : weaponBulletCounts) {
		std::cout << static_cast<int>(entry.first) << ": "
			<< entry.second << '\n';
	}

	return 0;
}
